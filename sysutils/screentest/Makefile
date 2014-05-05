# $NetBSD: Makefile,v 1.36 2014/05/05 00:48:22 ryoon Exp $

DISTNAME=	screentest-2.0
PKGREVISION=	20
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=screentest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://screentest.sourceforge.net/
COMMENT=	CRT/LCD screen testing utility using GTK+

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS+=	share/doc/screentest

post-install:
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/screentest
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
