# $NetBSD: Makefile,v 1.43 2014/02/12 23:18:24 tron Exp $

DISTNAME=	openslp-1.2.1
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

# Needs pkgviews-enabled automake
# PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		automake bison lex pax
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--enable-slpv2-security
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR} DOC_DIR=${DOCDIR}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONFS=			slp.conf slp.reg slp.spi
CONF_FILES=		# empty
.for file in ${CONFS}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
RCD_SCRIPTS=		slpd

INSTALLATION_DIRS=	share/doc/openslp

.include "../../security/openssl/buildlink3.mk"

post-extract:
	@${FIND} ${WRKSRC} -name "CVS" -print | ${XARGS} ${RM} -rf
	@${RM} -fr ${WRKSRC}/doc/html/UsersGuide/.xvpics

pre-configure:
	@cd ${WRKSRC} && aclocal && autoheader && autoconf &&		\
		${LOCALBASE}/bin/libtoolize && automake --add-missing

post-install:
	@cd ${WRKSRC}/doc && pax -rw . ${DESTDIR}${PREFIX}/share/doc/openslp
	@${FIND} ${DESTDIR}${PREFIX}/share/doc/openslp | ${XARGS} ${CHOWN} \
		${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DESTDIR}${PREFIX}/share/doc/openslp -type f | ${XARGS} ${CHMOD} \
		${SHAREMODE}
	@${FIND} ${DESTDIR}${PREFIX}/share/doc/openslp -type d | ${XARGS} ${CHMOD} \
		${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
