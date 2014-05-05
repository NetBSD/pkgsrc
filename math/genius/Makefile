# $NetBSD: Makefile,v 1.61 2014/05/05 00:48:07 ryoon Exp $
#

DISTNAME=		genius-1.0.17
PKGREVISION=		3
CATEGORIES=		math
MASTER_SITES=		http://ftp.5z.com/pub/genius/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jirka.org/genius.html
COMMENT=		Calculator and math tool
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c99
MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt

.include "options.mk"

do-test:
	(cd ${WRKSRC}/src; perl geniustest.pl)

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.18
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
