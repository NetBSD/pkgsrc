# $NetBSD: Makefile,v 1.15 2005/06/23 14:20:56 seb Exp $

DISTNAME=	flow-tools-0.68
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.splintered.net/sw/flow-tools/
COMMENT=	Collect and store NetFlow data

GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

PKG_SYSCONFSUBDIR=	flow-tools
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/flow-tools
MAKE_DIRS+=	${PKG_SYSCONFDIR}/sym
MAKE_DIRS+=	${PKG_SYSCONFDIR}/cfg

# These files are config files that are unlikely to be modified in most cases
# so we install them via SUPPORT_FILES.
_SYM_FILES=	ip-prot.sym ip-type.sym tcp-port.sym asn.sym tag.sym
.for _f_ in ${_SYM_FILES}
SUPPORT_FILES+=	${EGDIR}/sym/${_f_} ${PKG_SYSCONFDIR}/sym/${_f_}
.endfor
MESSAGE_SUBST+=	EGDIR=${EGDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.flow-tools
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_SUPPORTED_OPTIONS=		python
PKG_OPTIONS_GROUP.database=	mysql postgresql
PKG_OPTIONS_LEGACY_VARS+=	FLOW_TOOLS_USE_MYSQL:mysql
PKG_OPTIONS_LEGACY_VARS+=	FLOW_TOOLS_USE_POSTGRESQL:postgresql

.include "../../mk/bsd.options.mk"

# MySQL support.
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

# PostgreSQL support.
.if !empty(PKG_OPTIONS:Mpostgresql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.endif

# Python scripts support.
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"

PYTHON_PATCH_SCRIPTS=	bin/flow-rpt2rrd bin/flow-log2rrd bin/flow-rptfmt
PLIST_SUBST+=	PYTHON_OPT=""

post-install:
.   for s in flow-rpt2rrd flow-log2rrd flow-rptfmt
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${s} ${PREFIX}/bin/${s}
	${INSTALL_MAN} ${WRKSRC}/docs/${s}.1 ${PREFIX}/man/man1/${s}.1
.  endfor
.else
PLIST_SUBST+=	PYTHON_OPT="@comment "
.endif

# To avoid providing more patch files we do the following...
# Order is important here or else dependencies requiring docbook-to-man/jade
# will be triggered
post-patch:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC}/docs &&						\
	for m in flow-*.1.in; do					\
		h=`${BASENAME} $${m} .1.in`.html.in;			\
		s=`${BASENAME} $${m} .1.in`.sgml;			\
		for f in $${s} $${h} $${m}; do				\
			${MV} $${f} $${f}.bak &&			\
			${SED} -e 's,@localstatedir@,@sysconfdir@,g'	\
		   < $${f}.bak > $${f};					\
		done;							\
	done

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
