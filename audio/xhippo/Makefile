# $NetBSD: Makefile,v 1.20 2004/10/03 00:13:10 tv Exp $
#

DISTNAME=	xhippo-3.3
PKGREVISION=	4
CATEGORIES=	audio x11
MASTER_SITES=	${MASTER_SITE_GNU:=xhippo/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/xhippo/xhippo.html
COMMENT=	Generic playlist manager for UNIX

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ENV+=	--with-gnome=no

CONF_FILES=	${PREFIX}/share/doc/xhippo/xhippo.config.example \
		${PKG_SYSCONFDIR}/xhippo.config

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/xhippo.config \
		${PREFIX}/share/doc/xhippo/xhippo.config.example
	${INSTALL_DATA} ${WRKSRC}/xhippo.gtkrc \
		${PREFIX}/share/doc/xhippo/xhippo.gtkrc
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README.fvwm2 ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.ps.gz ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.txt.gz ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.sgml ${PREFIX}/share/doc/xhippo

.include "../../x11/gtk/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
