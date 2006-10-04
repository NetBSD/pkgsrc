# $NetBSD: Makefile,v 1.14 2006/10/04 21:49:19 wiz Exp $
#

DISTNAME=	fooseti-0.6.6
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www-personal.engin.umich.edu/~agorski/fooseti/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://www-personal.engin.umich.edu/~agorski/fooseti/
COMMENT=	Simple GTK+ frontend for the Seti@home client
BROKEN=		"Not compatible with new SETI@Home client"

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
