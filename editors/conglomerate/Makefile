# $NetBSD: Makefile,v 1.5 2003/09/27 02:46:09 xtraeme Exp $
#

DISTNAME=	conglomerate-0.7.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=conglomerate/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.conglomerate.org/
COMMENT=	XML editor for GNOME2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		docbook-xsl>=1.61.2:../../textproc/docbook-xsl
DEPENDS+=		docbook-xml>=4.2nb4:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
