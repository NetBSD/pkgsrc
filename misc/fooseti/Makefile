# $NetBSD: Makefile,v 1.2 2003/05/02 11:55:47 wiz Exp $
#

DISTNAME=	fooseti-0.6.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www-personal.engin.umich.edu/~agorski/fooseti/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www-personal.engin.umich.edu/~agorski/fooseti/
COMMENT=	Simple GTK+ frontend for the Seti@home client

DEPENDS+=	setiathome>=3.00:../../misc/setiathome

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

CPPFLAGS+=	-DPKG_BINDIR=\"\\\"${LOCALBASE}/bin\\\"\"

DOCS=		AUTHORS BUGS COPYING ChangeLog INSTALL NEWS NOTES README TODO

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fooseti
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/fooseti
.endfor
.undef doc

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
