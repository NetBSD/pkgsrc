# $NetBSD: Makefile,v 1.23.2.1 2005/05/27 10:44:30 salo Exp $

DISTNAME=	openslp-1.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

# Needs pkgviews-enabled automake
# PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		yacc lex
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-slpv2-security
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR} DOC_DIR=${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONFS=			slp.conf slp.reg slp.spi
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=		slpd

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/automake.mk"

post-extract:
	@${FIND} ${WRKSRC} -name "CVS" -print | ${XARGS} ${RM} -rf
	@${RM} -fr ${WRKSRC}/doc/html/UsersGuide/.xvpics

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER} && ${AUTOCONF} &&	\
		${LOCALBASE}/bin/libtoolize && ${AUTOMAKE} --add-missing

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openslp
	@cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/openslp
	@${FIND} ${PREFIX}/share/doc/openslp | ${XARGS} ${CHOWN} \
		${SHAREOWN}:${SHAREGRP}
	@${FIND} ${PREFIX}/share/doc/openslp -type f | ${XARGS} ${CHMOD} \
		${SHAREMODE}
	@${FIND} ${PREFIX}/share/doc/openslp -type d | ${XARGS} ${CHMOD} \
		${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
