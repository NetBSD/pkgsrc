# $NetBSD: Makefile,v 1.6 2004/04/22 15:33:35 seb Exp $

DISTNAME=	flow-tools-0.67
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://www.splintered.net/sw/flow-tools/
COMMENT=	Collect and store NetFlow data

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

PKG_SYSCONFSUBDIR=	flow-tools
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILD_DEFS+=	FLOW_TOOLS_USE_MYSQL
BUILD_DEFS+=	FLOW_TOOLS_USE_POSTGRESQL

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

.include "../../mk/bsd.prefs.mk"

# MySQL support
.if defined(FLOW_TOOLS_USE_MYSQL) && !empty(FLOW_TOOLS_USE_MYSQL:M[yY][eE][sS])
.include "../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

# Postgresql support
.if defined(FLOW_TOOLS_USE_POSTGRESQL) && !empty(FLOW_TOOLS_USE_POSTGRESQL:M[yY][eE][sS])
.include "../../databases/postgresql-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
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
