# $NetBSD: Makefile,v 1.7 2003/02/18 14:56:02 jmmv Exp $

DISTNAME=	seahorse-0.7.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://seahorse.sourceforge.net
COMMENT=	GnuPG front end and bonobo component for Gnome

DEPENDS=			gnupg>=1.2.1:../../security/gnupg
DEPENDS+=			gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILDLINK_DEPENDS.gpgme=	gpgme>=0.3.14

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS= 	seahorse.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
