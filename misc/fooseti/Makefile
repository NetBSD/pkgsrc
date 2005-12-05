# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:39 rillig Exp $
#

DISTNAME=	fooseti-0.6.6
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www-personal.engin.umich.edu/~agorski/fooseti/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www-personal.engin.umich.edu/~agorski/fooseti/
COMMENT=	Simple GTK+ frontend for the Seti@home client

DEPENDS+=	setiathome>=3.00:../../misc/setiathome

GNU_CONFIGURE=	YES

CPPFLAGS+=	-DPKG_BINDIR="\"${LOCALBASE}/bin\""

DOCS=		AUTHORS BUGS COPYING ChangeLog INSTALL NEWS NOTES README TODO

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fooseti
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/fooseti
.endfor

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
