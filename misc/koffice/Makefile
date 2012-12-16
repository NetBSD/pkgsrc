# $NetBSD: Makefile,v 1.141 2012/12/16 01:52:25 obache Exp $

DISTNAME=	koffice-1.6.3
PKGREVISION=	37
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-1.6.3/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

MAKE_JOBS_SAFE=		no

PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/
PATCHFILES=	koffice-xpdf-CVE-2007-3387.diff koffice-1.6.3-xpdf2-CVE-2007-4352-5392-5393.diff

CONFLICTS+=	koffice3-[0-9]*

# to unpack krita/plugins/convolutionfilters properly on NetBSD 1.6
## EXTRACT_USING=		gtar

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

GCC_REQD+=		2.95.3

PTHREAD_OPTS+=		require

CONFIGURE_ENV+=		PYTHONDIR=${LOCALBASE:Q}
CONFIGURE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

REPLACE_PERL+=		lib/store/fix_storage.pl
REPLACE_PERL+=		admin/config.pl
REPLACE_PERL+=		admin/bcheck.pl
REPLACE_PERL+=		admin/conf.change.pl
REPLACE_PERL+=		kword/templates/make_template.pl
REPLACE_PERL+=		tools/scripts/gdb_output_to_text.pl
REPLACE_PERL+=		tools/thesaurus/extract.pl
REPLACE_PERL+=		kpresenter/kprconverter.pl

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

.include "options.mk"

post-install:
	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	${CHMOD} u+w ${DESTDIR}${PREFIX}/share/kde/templates/.source/*

.include "../../lang/python/pyversion.mk"
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/poppler-qt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
