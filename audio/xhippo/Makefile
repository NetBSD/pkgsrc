# $NetBSD: Makefile,v 1.30 2012/10/02 23:48:14 asau Exp $
#

DISTNAME=	xhippo-3.3
PKGREVISION=	7
CATEGORIES=	audio x11
MASTER_SITES=	${MASTER_SITE_GNU:=xhippo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/xhippo/xhippo.html
COMMENT=	Generic playlist manager for UNIX

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=	--with-gnome=no

CONF_FILES=	${PREFIX}/share/doc/xhippo/xhippo.config.example \
		${PKG_SYSCONFDIR}/xhippo.config

INSTALLATION_DIRS=	share/doc/xhippo

post-install:
	${INSTALL_DATA} ${WRKSRC}/xhippo.config \
		${DESTDIR}${PREFIX}/share/doc/xhippo/xhippo.config.example
	${INSTALL_DATA} ${WRKSRC}/xhippo.gtkrc \
		${DESTDIR}${PREFIX}/share/doc/xhippo/xhippo.gtkrc
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README.fvwm2 ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.ps.gz ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.txt.gz ${DESTDIR}${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.sgml ${DESTDIR}${PREFIX}/share/doc/xhippo

.include "../../x11/gtk/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
