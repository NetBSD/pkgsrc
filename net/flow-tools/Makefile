# $NetBSD: Makefile,v 1.42 2022/06/30 11:18:41 nia Exp $

DISTNAME=	flow-tools-0.68
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.splintered.net/sw/flow-tools/
COMMENT=	Collect and store NetFlow data

USE_TOOLS+=	lex
GNU_CONFIGURE=	YES

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int32_t=uint32_t

PKG_SYSCONFSUBDIR=	flow-tools
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/flow-tools
MAKE_DIRS+=	${PKG_SYSCONFDIR}/sym
MAKE_DIRS+=	${PKG_SYSCONFDIR}/cfg

_SYM_FILES=	ip-prot.sym ip-type.sym tcp-port.sym asn.sym tag.sym
.for _f_ in ${_SYM_FILES}
CONF_FILES+=	${EGDIR}/sym/${_f_} ${PKG_SYSCONFDIR}/sym/${_f_}
.endfor
MESSAGE_SUBST+=	EGDIR=${EGDIR}

PKG_OPTIONS_VAR=		PKG_OPTIONS.flow-tools
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_SUPPORTED_OPTIONS=		python
PKG_OPTIONS_GROUP.database=	mysql pgsql

.include "../../mk/bsd.options.mk"

# MySQL support.
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

# PostgreSQL support.
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.endif

# Python scripts support.
PLIST_VARS+=		python
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"

REPLACE_PYTHON=	bin/flow-rpt2rrd bin/flow-log2rrd bin/flow-rptfmt
PLIST.python=	yes

post-install:
.  for s in flow-rpt2rrd flow-log2rrd flow-rptfmt
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${s} ${PREFIX}/bin/${s}
	${INSTALL_MAN} ${WRKSRC}/docs/${s}.1 ${PREFIX}/${PKGMANDIR}/man1/${s}.1
.  endfor
.endif

# To avoid providing more patch files we do the following...
# Order is important here or else dependencies requiring docbook-to-man/jade
# will be triggered
post-patch:
	${RUN}								\
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
