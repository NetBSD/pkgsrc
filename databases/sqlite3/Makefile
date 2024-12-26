# $NetBSD: Makefile,v 1.161 2024/12/26 22:04:28 riastradh Exp $

.include "Makefile.common"

DISTNAME=	sqlite-autoconf-${SQLITE3_DISTVERSION}
PKGNAME=	sqlite3-${SQLITE3_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQL Database Engine in a C Library

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-static-shell

PKGCONFIG_OVERRIDE+=	sqlite3.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# sqlite3 compile options are documented at:
#
# https://www.sqlite.org/compile.html
#
# We always enable those options that:
#
# (a) are not dynamically loadable, but
# (b) enable functionality applications are likely to require, and
# (c) do not change default settings, and
# (d) do not bring unwieldy dependencies, and
# (e) do not incur unreasonable burden on users not needing them if
#     applicable only to niche use cases.
#
# We also always enable options that are necessary to build, or are
# performance optimizations that do not affect functionality.
#
# Other options -- those that can be dynamically loaded, those that
# change defaults which applications could override anyway, or those
# that bring in unwieldy dependencies -- are relegated to options.mk,
# e.g. the `icu' option which brings in the unwieldy dependency of
# textproc/icu.
#
# Where both a configure argument option and a C preprocessor macro
# option are available, we prefer the configure argument so that it is
# checked by the configure script to detect potential bitrot in the
# future.

### Build fixes

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
# and lacks the zone memory allocator
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=		-DSQLITE_ENABLE_LOCKING_STYLE=0
CFLAGS+=		-DSQLITE_WITHOUT_ZONEMALLOC
.endif

### Performance optimizations

# In the past, Linux had database corruption issues with pread, so only
# enable it on safe platforms.  This (undocumented) option enables the
# use of pread(2), instead of the sequence of syscalls
# lseek(2)-then-read(2), to read from a specific position in a file.
CFLAGS.NetBSD+=		-DUSE_PREAD

### Enabled functionality

# SQLITE_THREADSAFE.  Some applications of sqlite3 in pkgsrc require
# thread-safety, so we enable this for everyone.  Applications that
# really benefit from omitting mutexes and similar can statically link
# a custom build of sqlite3.  We pass the arguments to make sure they
# stay enabled in case upstream ever changes the default until we
# review the change.
CONFIGURE_ARGS+=	--enable-threadsafe

# The column metadata API provides some additional information about
# the provenance of columns in query results, and is not dynamically
# loadable:
#
# https://www.sqlite.org/c3ref/column_database_name.html
# https://www.sqlite.org/compile.html#enable_column_metadata
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA

# The DBSTAT virtual table provides information about disk space
# utilization, is required by lang/tcl's bin/sqlite3_analyzer, and is
# not (as far as I can tell) dynamically loadable:
#
# https://www.sqlite.org/dbstat.html
# https://www.sqlite.org/compile.html#enable_dbstat_vtab
CFLAGS+=		-DSQLITE_ENABLE_DBSTAT_VTAB

# Full-text search engines.  There are two full-text search engines,
# fts3/4 and fts5.  The options SQLITE_ENABLE_FTS3 and
# SQLITE_ENABLE_FTS4 are equivalent; we enable both to make it clear
# that that is intended.  fts3 has been available since 3.5.0 in 2007,
# the fts4 extension (which is unconditionally bundled with the fts3
# build option now) since 3.7.4 in 2010, fts5 since 3.9.0 in 2015, and
# all are enabled by default.  We pass the arguments to make sure they
# stay enabled in case upstream ever changes the default until we
# review the change.
#
# In principle, fts5 is dynamically loadable, but since upstream
# enables it by default anyway we treat that as a moot point.
#
# https://www.sqlite.org/fts3.html
# https://www.sqlite.org/fts5.html
# https://www.sqlite.org/compile.html#enable_fts3
# https://www.sqlite.org/compile.html#enable_fts4
# https://www.sqlite.org/compile.html#enable_fts5
CONFIGURE_ARGS+=	--enable-fts3 # -DSQLITE_ENABLE_FTS3
CONFIGURE_ARGS+=	--enable-fts4 # -DSQLITE_ENABLE_FTS4
CONFIGURE_ARGS+=	--enable-fts5 # -DSQLITE_ENABLE_FTS5

# Nested queries and AND/OR operators for fts3/4.
#
# https://www.sqlite.org/fts3.html#_set_operations_using_the_enhanced_query_syntax
# https://www.sqlite.org/compile.html#enable_fts3_parenthesis
CFLAGS+=		-DSQLITE_ENABLE_FTS3_PARENTHESIS

# SQLITE_ENABLE_GEOPOLY, SQLITE_ENABLE_RTREE -- R*Tree and Geopoly
# interface for geospatial queries.  Enabled by default since 2018.  We
# pass the arguments to make sure they stay enabled in case upstream
# ever changes the default until we review the change.
#
# https://www.sqlite.org/geopoly.html
# https://www.sqlite.org/rtree.html
# https://www.sqlite.org/compile.html#enable_geopoly
# https://www.sqlite.org/compile.html#enable_rtree
CONFIGURE_ARGS+=	--enable-rtree

# SQLITE_ENABLE_ICU -- unwieldy dependency, relegated to options.mk.
# https://www.sqlite.org/compile.html#enable_icu

# SQLITE_ENABLE_IOTRACE -- experimental and may be discontinued in a
# future release.
# https://www.sqlite.org/compile.html#enable_iotrace

# Hidden columns.  Allows virtual tables to declare certain columns
# HIDDEN, which hides them from PRAGMA table_info, SELECT *, and
# implicit INSERT.
#
# https://www.sqlite.org/vtab.html#hiddencol
# https://www.sqlite.org/compile.html#enable_hidden_columns
CFLAGS+=		-DSQLITE_ENABLE_HIDDEN_COLUMNS

# SQLITE_ENABLE_JSON1 -- JSON1 support, built-in functions for
# manipulating JSON.  Enabled by default since 2022, configure option
# removed, compile-time option switched from opt-in to opt-out in
# sqlite3>=3.38.0.
#
# https://www.sqlite.org/json1.html
# https://www.sqlite.org/compile.html#enable_json1

# SQLITE_ENABLE_LOCKING_STYLE -- relevant mainly (only?) on Apple
# systems, where it is enabled by default anyway.
#
#	This option enables additional logic in the OS interface layer
#	for Mac OS X.  The additional logic attempts to determine the
#	type of the underlying filesystem and choose and alternative
#	locking strategy that works correctly for that filesystem type.
#
# Note issue with Darwin < 9 (Mac OS X < 10.5 "Leopard") above.
#
# https://www.sqlite.org/compile.html#enable_locking_style

# SQLITE_ENABLE_MATH_FUNCTIONS -- SQL math functions: sin/cos/tan,
# log/exp, floor/ceil/trunc, &c.  We pass the arguments to make sure
# they stay enabled in case upstream ever changes the default until we
# review the change.
#
# https://www.sqlite.org/lang_mathfunc.html
# https://www.sqlite.org/compile.html#enable_math_functions
CONFIGURE_ARGS+=	--enable-math

# XXX Consider SQLITE_ENABLE_MEMORY_MANAGEMENT.
#
#	This option adds extra logic to SQLite that allows it to
#	release unused memory upon request.  This option must be
#	enabled in order for the sqlite3_release_memory() interface to
#	work.  If this compile-time option is not used, the
#	sqlite3_release_memory() interface is a no-op.
#
# https://www.sqlite.org/compile.html#enable_memory_management

# SQLITE_ENABLE_MEMSYS3, SQLITE_ENABLE_MEMSYS5 -- alternative memory
# allocators, mutually exclusive.  These seem likely to be relevant
# only for specialized applications having unusual dynamic memory
# allocation requirements, so although this does enable extra
# functionality (SQLITE_CONFIG_HEAP,
# https://www.sqlite.org/c3ref/c_config_covering_index_scan.html#sqliteconfigheap),
# it's not clear which allocator is appropriate to ship by default so
# we will not enable either one.
#
# https://www.sqlite.org/compile.html#enable_memsys3
# https://www.sqlite.org/compile.html#enable_memsys5

# XXX Consider -DSQLITE_ENABLE_NORMALIZE.
#
#	This option includes the sqlite3_normalized_sql() API.
#
# Unclear what runtime consequences this has.  Unclear what
# applications outside https://github.com/bloomberg/comdb2 use this.
#
# https://www.sqlite.org/compile.html#enable_normalize
#
# Gentoo enables: https://gitweb.gentoo.org/repo/gentoo.git/tree/dev-db/sqlite/sqlite-3.47.2.ebuild?id=be159693998b95bddf9c118b2425d9f8a2365a67#n211
#
# Arch Linux does not: https://gitlab.archlinux.org/archlinux/packaging/packages/sqlite/-/blob/bf41f088e6ca945d9374838780d5bacb47653277/PKGBUILD#L42-53
# Debian does not: https://sources.debian.org/src/sqlite3/3.46.1-1/debian/rules/#line43
# Fedora does not: https://src.fedoraproject.org/rpms/sqlite/blob/182717934c83e9d3ec80f9f818961fd21640c964/f/sqlite.spec#_189
# FreeBSD does not: https://cgit.freebsd.org/ports/tree/databases/sqlite3/Makefile?id=8d38e8fbf53dfc94507a466b7269b38a55b167ac#n70
# Homebrew does not: https://github.com/Homebrew/homebrew-core/blob/f6ac42c098379841c21ed3a30e150f26187f34b1/Formula/s/sqlite.rb#L35-L58
# OpenBSD does not: https://cvsweb.openbsd.org/ports/databases/sqlite3/Makefile?rev=1.132&content-type=text/x-cvsweb-markup
#
# https://www.sqlite.org/compile.html#enable_normalize

# SQLITE_ENABLE_NULL_TRIM -- minor on-disk space optimization with some
# compatibility issues and potentially blob API bugs.  We will let
# sleeping dogs lie here.
#
# https://www.sqlite.org/compile.html#enable_null_trim

# XXX Consider -DSQLITE_ENABLE_OFFSET_SQL_FUNC.
#
# Unclear what applications need this.  Gentoo and Fedora enable this;
# others I checked do not.
#
#	This option enables support for the sqlite_offset(X) SQL
#	function.
#
#	The sqlite_offset(X) SQL function requires a new interface on
#	the B-tree storage engine, a new opcode in the virtual machine
#	that runs SQL statements, and a new conditional in a critical
#	path of the code generator.  To avoid that overhead in
#	applications that do not need the utility of sqlite_offset(X),
#	the function is disabled by default.
#
# https://www.sqlite.org/compile.html#enable_offset_sql_func
#
#	The sqlite_offset(X) function returns the byte offset in the
#	database file for the beginning of the record from which value
#	would be read.  If X is not a column in an ordinary table, then
#	sqlite_offset(X) returns NULL.  The value returned by
#	sqlite_offset(X) might reference either the original table or
#	an index, depending on the query.  If the value X would
#	normally be extracted from an index, the sqlite_offset(X)
#	returns the offset to the corresponding index record.  If the
#	value X would be extracted from the original table, then
#	sqlite_offset(X) returns the offset to the table record.
#
# https://www.sqlite.org/lang_corefunc.html#sqlite_offset

# XXX Consider SQLITE_ENABLE_ORDERED_SET_AGGREGATES.
#
#	This option enables support for the "WITHIN GROUP ORDER BY"
#	ordered-set aggregate syntax.  For example:
#
#	    SELECT percentile_cont(0.75) WITHIN GROUP (ORDER BY x) FROM tab;
#
#	The above is the SQL-standard way to compute the 75-percentile
#	value of a distribution.  The usual way to do this in SQLite is
#	as follows:
#
#	    SELECT percentile_cont(x,0.75) FROM tab;
#
#	Though simpler, easier to read, and easier to type, this syntax
#	is not compliant with standard SQL.  The simpler, non-standard
#	syntax is always available in SQLite.  But the SQL-standard
#	compliant syntax is only available if compiled using
#	-DSQLITE_ENABLE_ORDERED_SET_AGGREGATES.  The SQL-standard
#	compliant syntax is disabled by default because (A) it requires
#	about 1,200 bytes of extra code in the compiled SQLite binary
#	and (B) because it makes your SQL code more difficult to read,
#	write, and understand without adding any value.  Use this
#	option only if you need to write cross-platform SQL that uses
#	ordered-set aggregate functions such as percentile_cont().
#
# This might be useful for generic database wrappers that use this
# package for a sqlite3 backend.  But nobody else seems to enable this.
# So let's hold off until the need arises.
#
# https://www.sqlite.org/compile.html#enable_ordered_set_aggregates

# SQLITE_ENABLE_PREUPDATE_HOOK, SQLITE_ENABLE_SESSION -- enables the
# sqlite3_preupdate_* for pre-update hooks, and the sqlite3session_*
# APIs for reifying changesets.
#
# https://www.sqlite.org/c3ref/preupdate_blobwrite.html
# https://www.sqlite.org/sessionintro.html
# https://www.sqlite.org/compile.html#enable_preupdate_hook
# https://www.sqlite.org/compile.html#enable_session
CONFIGURE_ARGS+=	--enable-session

# SQLITE_ENABLE_QPSG -- query planner stability guarantee.  Off by
# default.  This option turns it on by default.  Applications can
# always use sqlite3_db_config(SQLITE_DBCONFIG_ENABLE_QPSG) to enable
# it at run-time, so no need for us to build sqlite3 with it.
#
# https://www.sqlite.org/queryplanner-ng.html#qpstab
# https://www.sqlite.org/compile.html#enable_qpsg

# XXX Consider SQLITE_ENABLE_RBU, Resumable Bulk Updates.
#
# Gentoo enables this; nobody else I found does.
#
# https://www.sqlite.org/rbu.html
# https://www.sqlite.org/compile.html#enable_rbu

# XXX Consider SQLITE_ENABLE_SNAPSHOT, write-ahead log snapshots.
#
# Unclear what applications might use this.  Nobody else seems to
# enable this.
#
# https://www.sqlite.org/c3ref/snapshot.html
# https://www.sqlite.org/compile.html#enable_snapshot

# SQLITE_ENABLE_SORTER_REFERENCES -- potential optimization whose value
# is not clear, off by default.
#
# https://www.sqlite.org/compile.html#enable_sorter_references

# SQLITE_ENABLE_STMT_SCANSTATUS -- enables sqlite3_stmt_scanstatus and
# sqlite3_stmt_scanstatus_v2.
#
#	 Those interfaces are normally omitted from the build because
#	 they imposes a performance penalty, even on statements that do
#	 not use the feature.
#
# https://www.sqlite.org/c3ref/stmt_scanstatus.html
# https://www.sqlite.org/compile.html#enable_stmt_scanstatus

# The SQLITE_STMT virtual table provides information about all prepared
# statements associated with the database connection.  This is likely
# to be useful for performance analysis of applications and does not
# appear to have any performance penalty for applications that don't
# use it.
#
# https://www.sqlite.org/stmt.html
# https://www.sqlite.org/compile.html#enable_stmtvtab
CFLAGS+=		-DSQLITE_ENABLE_STMTVTAB

# SQLITE_RTREE_INT_ONLY
#
#	This compile-time option is deprecated and untested.
#
# https://www.sqlite.org/compile.html#rtree_int_only

# SQLITE_ENABLE_SQLLOG
#
#	This option enables extra code (especially the
#	SQLITE_CONFIG_SQLLOG option to sqlite3_config()) that can be
#	used to create logs of all SQLite processing performed by an
#	application.
#
# Unclear what applications use this or what it does beyond
# sqlite3_trace_v2 (https://www.sqlite.org/c3ref/trace_v2.html).  Can't
# find anyone else who enables this.
#
# https://www.sqlite.org/c3ref/c_config_covering_index_scan.html#sqliteconfigsqllog
# https://www.sqlite.org/compile.html#enable_sqllog

# SQLITE_ENABLE_STAT2, SQLITE_ENABLE_STAT3, SQLITE_ENABLE_STAT4 --
# statistics tables created by the ANALYZE command.
# SQLITE_ENABLE_STAT2 and SQLITE_ENABLE_STAT3 are now ignored.
# SQLITE_ENABLE_STAT4 is not enabled by default and it's unclear what
# the performance implications are, but it appears likely to expand
# disk usage and potentially break the query planner stability
# guarantee, so we'll leave it off for now.
#
# https://www.sqlite.org/fileformat2.html#stat4tab
# https://www.sqlite.org/compile.html#enable_stat2
# https://www.sqlite.org/compile.html#enable_stat3
# https://www.sqlite.org/compile.html#enable_stat4

# SQLITE_ENABLE_TREE_EXPLAIN
#
#	This compile-time option is no longer used.
#
# https://www.sqlite.org/compile.html#enable_tree_explain

# XXX Consider SQLITE_ENABLE_UPDATE_DELETE_LIMIT:
#
#	This option enables an optional ORDER BY and LIMIT clause on
#	UPDATE and DELETE statements.
#
# Unclear what applications might rely on this.  Debian and Gentoo
# enable this by default; others do not.
#
# https://www.sqlite.org/compile.html#enable_update_delete_limit

# XXX Consider SQLITE_ENABLE_UNKNOWN_SQL_FUNCTION -- enables the
# `unknown()' function for (and only for) EXPLAIN or EXPLAIN QUERY
# PLAN, as a substitute for any functions sqlite3 does not recognize.
#
#	When used in the command-line shell, the
#	SQLITE_ENABLE_UNKNOWN_SQL_FUNCTION feature allows SQL text that
#	contains application-defined functions to be pasted into the
#	shell for analysis and debugging without having to create and
#	load an extension that implements the application-defined
#	functions.
#
# However, this might be useful _only_ for the command-line shell;
# unclear what applications might rely on failure vs unknown().
#
# https://www.sqlite.org/compile.html#enable_unknown_sql_function

# SQLITE_ENABLE_UNLOCK_NOTIFY -- enables sqlite3_unlock_notify(),
# needed for various sqlite3 API calls to sleep rather than fail with
# SQLITE_LOCKED when another thread is using another connection to the
# same database, so they can be woken by the other thread when it is
# done.  Needed by, e.g., Firefox.
#
# https://www.sqlite.org/unlock_notify.html
# https://www.sqlite.org/compile.html#enable_unlock_notify
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY

# SQLITE_INTROSPECTION_PRAGMAS
#
#	This option is obsolete.
#
# https://www.sqlite.org/compile.html#introspection_pragmas

# XXX Consider SQLITE_SOUNDEX:
#
#	This option enables the soundex() SQL function.
#
# Debian and Gentoo enable this by default; others do not.
#
# https://www.sqlite.org/lang_corefunc.html#soundex
# https://www.sqlite.org/compile.html#soundex

# XXX Consider SQLITE_STRICT_SUBTYPE=1:
#
#	This option causes application-defined SQL functions to raise
#	an SQL error if they invoke the sqlite3_result_subtype()
#	interface but where not registered with the
#	SQLITE_RESULT_SUBTYPE property.  This recommended option helps
#	to identify problems in the implementation of
#	application-defined SQL functions early in the development
#	cycle.
#
# Debian and FreeBSD enable this; others do not.
#
# https://www.sqlite.org/compile.html#strict_subtype

# XXX Consider SQLITE_USE_ALLOCA:
#
#	If this option is enabled, then the alloca() memory allocator
#	will be used in a few situations where it is appropriate.  This
#	results in a slightly smaller and faster binary.  The
#	SQLITE_USE_ALLOCA compile-time only works, of course, on
#	systems that support alloca().
#
# Nobody else seems to enable this.
#
# https://www.sqlite.org/compile.html#use_alloca

# XXX Consider SQLITE_USE_FCNTL_TRACE:
#
#	This option causes SQLite to issue extra SQLITE_FCNTL_TRACE
#	file controls to provide supplementary information to the VFS.
#	The "vfslog.c" extension makes use of this to provide enhanced
#	logs of VFS activity.
#
# Nobody else seems to enable this.  Unclear what applications this
# benefits.
#
# https://www.sqlite.org/compile.html#use_fcntl_trace

# SQLITE_USE_SEH
#
#	Client code should not use this define, as it is used
#	internally by the library.
#
# https://www.sqlite.org/compile.html#use_seh

# XXX Consider SQLITE_HAVE_ZLIB:
#
#	This option has no effect on the SQLite core.  It is only used
#	by extensions.  This is option is necessary for the compression
#	and decompression functions that are part of SQL Archive
#	support in the command-line shell.
#
# https://www.sqlite.org/compile.html#have_zlib

# XXX Consider YYTRACKMAXSTACKDEPTH:
#
#	This option causes the LALR(1) parser stack depth to be tracked
#	and reported using the
#	sqlite3_status(SQLITE_STATUS_PARSER_STACK,...)  interface.
#	SQLite's LALR(1) parser has a fixed stack depth (determined at
#	compile-time using the YYSTACKDEPTH options).  This option can
#	be used to help determine if an application is getting close to
#	exceeding the maximum LALR(1) stack depth.

# SQLITE_OMIT_LOAD_EXTENSION (old: !SQLITE_ENABLE_LOAD_EXTENSION)
#
# Make sure this is consistently enabled on all platforms -- this way
# the build fails early if something goes wrong with getting at dlopen.
# (XXX If we have platforms without dlopen, we may want to disable this
# on those platforms.)
#
# https://www.sqlite.org/compile.html#omit_load_extension
CONFIGURE_ARGS+=	--enable-load-extension

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

# Solaris needs -lrt for nanosleep, PR pkg/58714
LIBS.SunOS+=		-lrt

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lpthread
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
