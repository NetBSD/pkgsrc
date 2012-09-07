# $NetBSD: Makefile,v 1.44 2012/09/07 19:17:05 adam Exp $
#

DISTNAME=		genius-1.0.15
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		http://ftp.5z.com/pub/genius/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jirka.org/genius.html
COMMENT=		Calculator and math tool
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_GNU_READLINE=	yes

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
