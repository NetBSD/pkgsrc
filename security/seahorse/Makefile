# $NetBSD: Makefile,v 1.10 2003/05/27 17:17:38 jmmv Exp $

DISTNAME=	seahorse-0.7.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	GnuPG front end and bonobo component for Gnome

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnupg>=1.2.1:../../security/gnupg
DEPENDS+=		gnome2-dirs>=1.1:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS= 	seahorse.schemas

post-patch:
.for f in Makefile.in seahorse-context.c seahorse-marshal.c seahorse-marshal.h
	${MV} ${WRKSRC}/src/$f ${WRKSRC}/src/$f.orig
	${SED} -e 's/seahorse-marshal/seahorse_marshal/g' \
		< ${WRKSRC}/src/$f.orig > ${WRKSRC}/src/$f
.endfor
	${MV} ${WRKSRC}/src/seahorse-marshal.c ${WRKSRC}/src/seahorse_marshal.c
	${MV} ${WRKSRC}/src/seahorse-marshal.h ${WRKSRC}/src/seahorse_marshal.h
	${MV} ${WRKSRC}/src/seahorse-marshal.list \
		${WRKSRC}/src/seahorse_marshal.list

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
