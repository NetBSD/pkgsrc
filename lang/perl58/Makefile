# $NetBSD: Makefile,v 1.81 2005/05/11 16:15:50 jlam Exp $

# The following two variables should have empty values unless we're
# building a perl snapshot or release candidate.
#
PERL5_SNAPSHOT=	# empty
PERL5_RC_VERS=	# empty

PERL5_VERS=	5.8.6
CATEGORIES=	lang devel perl5
EXTRACT_SUFX=	.tar.bz2

.if empty(PERL5_SNAPSHOT) && empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}
PKGNAME=	perl-${PERL5_VERS}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S,/modules/by-module/$,/src/,}
.else
.  if !empty(PERL5_SNAPSHOT)
DISTNAME=	perl@${PERL5_SNAPSHOT}
PKGNAME=	perl-${PERL5_VERS}beta${PERL5_SNAPSHOT}
MASTER_SITES=	http://www.iki.fi/jhi/
EXTRACT_SUFX=	.tbz
WRKSRC=		${WRKDIR}/perl
.  else # !empty(PERL5_RC_VERS)
DISTNAME=	perl-${PERL5_VERS}-RC${PERL5_RC_VERS}
PKGNAME=	perl-${PERL5_VERS}rc${PERL5_RC_VERS}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/J/JH/JHI
.  endif
.endif

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.perl.com/
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-5.00* perl-base-[0-9]* \
		p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2] \
		p5-Data-Dumper-2.1[0-9][0-9] p5-Data-Dumper-[0-9][0-9] \
		p5-Devel-DProf-[0-9]* p5-Devel-Peek-[0-9]* \
		perl-mk-[0-9]* perl-thread-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/compiler.mk"

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Dscriptdir="${PREFIX}/bin"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Dcc="${CC}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dinstallstyle="lib/perl5"
CONFIGURE_ARGS+=	-Duseshrplib
CONFIGURE_ARGS+=	-Ui_malloc
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl
MAKE_ENV+=		LC_ALL="C"

TEST_TARGET=		test

# Install Perl man3 pages into a private directory under the normal
# Perl installation.  Also install site-specific Perl man3 pages into a
# private directory within site_perl.  This avoids manpage conflicts
# between 3rd-party modules, the standard Perl library, and other
# packages.
#
CONFIGURE_ARGS+=	-Dman3ext="3"
CONFIGURE_ARGS+=	-Dman3dir="${PERL5_PRIVLIB}/man/man3"
CONFIGURE_ARGS+=	-Dsiteman3dir="${PERL5_SITEPERL}/man/man3"

# Ensure that the Perl man1 pages go into ${PREFIX}/man/man1 and not
# into some other platform-specific location kindly "guessed" by the
# Configure script.
#
CONFIGURE_ARGS+=	-Dman1dir="${PREFIX}/man/man1"

# The site directories are all relative to the perl view.
CONFIGURE_ARGS+=	-Dsiteprefix="${VIEWBASE}"
CONFIGURE_ARGS+=	-Dsiteman1dir="${VIEWBASE}/man/man1"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
#
# The perl build attempts to work around case-insensitivity problems on
# HFS filesystems by using GNUmakefiles, so we need to use GNU make.
#
USE_GNU_TOOLS+=	make
.endif

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Darwin=	m c
LIBSWANTED.FreeBSD=	m crypt
LIBSWANTED.IRIX=	m crypt
LIBSWANTED.Interix=	m dl
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.OpenBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl
LIBSWANTED=		${LIBSWANTED.${OPSYS}}

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.Darwin=	/usr/lib
SYSLIBPATH.FreeBSD=	/usr/lib
SYSLIBPATH.Interix=	/usr/lib
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.OpenBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib
SYSLIBPATH=		${SYSLIBPATH.${OPSYS}}

# Nail down the directories in which headers and libraries of
# locally-installed software may be found.
#
LOCLIBPATH=		${LOCALBASE}/lib
LOCINCPATH=		${LOCALBASE}/include

# On a.out platforms, we link with "ld" and on ELF platforms, we link with
# "cc", so we need to use different options to pass the run-time search path
# flags to the link command in the right way.
#
.if ${OBJECT_FMT} == "a.out"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/${LINKER_RPATH_FLAG} /g}
.elif ${OBJECT_FMT} == "ELF"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/${COMPILER_RPATH_FLAG}/g}
.else
LOCLIBRPATHFLAGS=	# empty
.endif

PERL5_HINTS_LDFLAGS=	# empty
PERL5_HINTS_LDDLFLAGS=	# empty

PERL5_HINTS_LDFLAGS+=	${LOCLIBRPATHFLAGS}

.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

# By default, build with threads only if the threads are native.
.if !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
PERL5_USE_THREADS?=	yes
.else
PERL5_USE_THREADS?=	${DLOPEN_REQUIRE_PTHREADS}
.endif

### [Sat Dec 18 17:29:44 EST 2004 : jlam]
### Native threading on VAX isn't ready for primetime in NetBSD>=2.0.
### Build Perl without threads-support until VAX native threads are
### known to work.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-vax)
PKG_HACKS+=		broken-vax-pthreads
PERL5_USE_THREADS=	no
.endif

.if !empty(PERL5_USE_THREADS:M[nN][oO])
CONFIGURE_ARGS+=	-Uuseithreads
.else
.  include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	-Duseithreads
CFLAGS+=		${PTHREAD_CFLAGS}
PERL5_HINTS_LDFLAGS+=	${PTHREAD_LDFLAGS}
PERL5_HINTS_LDDLFLAGS+=	${PTHREAD_LDFLAGS}
LIBSWANTED+=		${PTHREAD_LIBS:M-l*:S/^-l//}
.endif

.if !empty(LIBSWANTED)
CONFIGURE_ARGS+=	-Dlibswanted="${LIBSWANTED}"
.endif

.include "../../mk/compiler.mk"

.if ${OPSYS} == "IRIX" && ${ABI} == "64"
CONFIGURE_ARGS+=	-Dcc='${CC} -64' -Duse64bitint
.endif

PERL5=			${PREFIX}/bin/perl${PERL5_VERS}
PERL5_PRIVLIB=		${PREFIX}/lib/perl5/${PERL5_VERS}
PERL5_SITEPERL=		${VIEWBASE}/lib/perl5/site_perl
PERL5_SITELIB=		${VIEWBASE}/lib/perl5/site_perl/${PERL5_VERS}
PLIST_SUBST+=		PERL5_SITEPERL=${PERL5_SITEPERL:S/^${PREFIX}\///}
PLIST_SUBST+=		PERL5_SITELIB=${PERL5_SITELIB:S/^${PREFIX}\///}
MESSAGE_SUBST+=		PERL5_SITELIB=${PERL5_SITELIB}

# Some platforms may want the directory mode not to be 0755.  This is,
# unfortunately, hardcoded in quite a few places in Perl.  So let's substitute
# what pkgsrc said instead.
post-patch:
.if ${PKGDIRMODE} != "755"
.  for f in installhtml installman installperl lib/ExtUtils/Install.pm
	cd ${WRKSRC} && \
		${MV} -f $f $f.dirmode && \
		${SED} -e 's/755/${PKGDIRMODE}/g;/umask(/d' \
		$f.dirmode >$f
.  endfor
.endif

# It's tough to guess which hints file will be used, so add our modifications
# to all of them:
#
# - Explicitly set the local compiler search paths to contain only the
#   pkgsrc-controlled directories.
#
pre-configure:
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		( ${ECHO} "";						\
		  ${ECHO} "cat > UU/pkgsrc.cbu <<'EOCBU'";		\
		  ${ECHO} "# This script UU/pkgsrc.cbu will get 'called-back' by Configure to set"; \
		  ${ECHO} '# linker options after all other call-back scripts have been invoked.'; \
		  ${ECHO} 'ldflags="${PERL5_HINTS_LDFLAGS} $$ldflags"';	\
		  ${ECHO} 'lddlflags="${PERL5_HINTS_LDFLAGS} $$lddlflags"'; \
		  ${ECHO} "EOCBU";					\
		) >> $${hints};						\
	done
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		( ${ECHO} "";						\
		  ${ECHO} "# Set pkgsrc defaults for library and header search paths."; \
		  ${ECHO} 'locincpth="${LOCINCPATH}"';			\
		  ${ECHO} 'loclibpth="${LOCLIBPATH}"';			\
		) >> $${hints};						\
	done
.if !empty(SYSLIBPATH)
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		( ${ECHO} "glibpth='${SYSLIBPATH}'";			\
		) >> $${hints};						\
	done
.endif

WRKSRC_PERL5=	${WRKSRC}/perl
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
PLIST_FILE_SED=	-e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,,"
PLIST_DIR_SED=	${PLIST_FILE_SED}					\
		-e "s,^,@unexec \${RMDIR} -p %D/,"			\
		-e "s,/[^/]*$$, 2>/dev/null || ${TRUE},"		\

post-install:
	${RM} -f ${PREFIX}/bin/perl ${PREFIX}/bin/perl${PERL5_VERS}
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC_PERL5} ${PREFIX}/bin/perl${PERL5_VERS}
	${LN} -f ${PREFIX}/bin/perl${PERL5_VERS} ${PREFIX}/bin/perl
.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL)
	if [ -x ${PREFIX}/bin/a2p ]; then				\
		strip ${PREFIX}/bin/a2p;				\
	fi
.endif
	# Generate the PLIST template
	eval `${PERL5} -V:installarchlib 2>/dev/null`;			\
	eval `${PERL5} -V:installsitearch 2>/dev/null`;			\
	sitearch=`${ECHO} $$installsitearch | ${SED} ${PLIST_FILE_SED}`; \
	${RMDIR} -p $$installsitearch 2>/dev/null || ${TRUE};		\
	packlist="$$installarchlib/.packlist";				\
	( ${ECHO} "@unexec ${RM} -f %D/$$sitearch/perllocal.pod";	\
	  ${ECHO} "@unexec ${RMDIR} -p %D/$$sitearch 2>/dev/null || ${TRUE}"; \
	  ${CAT} ${PKGDIR}/PLIST;					\
	  ${ECHO} "@comment The following lines are automatically generated"; \
	  ${ECHO} "@comment from the installed .packlist files.";	\
	) > ${PLIST_SRC};						\
	( ${ECHO} "$$packlist" && ${CAT} $$packlist )			\
	| ${SED} ${PLIST_FILE_SED} | ${SORT} -u >> ${PLIST_SRC};	\
	( ${ECHO} "$$packlist" && ${CAT} $$packlist )			\
	| ${SED} ${PLIST_DIR_SED} | ${SORT} -ur >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
