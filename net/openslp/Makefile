# $NetBSD: Makefile,v 1.21 2005/02/17 19:13:53 reed Exp $

DISTNAME=	openslp-1.2.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		yacc
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
	${FIND} ${WRKSRC} -name "CVS" -print | ${XARGS} ${RM} -rf
	${RM} -fr ${WRKSRC}/doc/html/UsersGuide/.xvpics

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER} && ${AUTOCONF} &&	\
		${LOCALBASE}/bin/libtoolize && ${AUTOMAKE} --add-missing

.include "../../mk/bsd.pkg.mk"
