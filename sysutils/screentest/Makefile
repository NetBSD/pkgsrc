# $NetBSD: Makefile,v 1.27 2012/10/02 17:12:01 tron Exp $

DISTNAME=	screentest-2.0
PKGREVISION=	12
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=screentest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://screentest.sourceforge.net/
COMMENT=	CRT/LCD screen testing utility using GTK+

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS+=	share/doc/screentest

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/screentest
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
