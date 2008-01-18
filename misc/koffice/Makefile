# $NetBSD: Makefile,v 1.100 2008/01/18 05:08:36 tnn Exp $

DISTNAME=	koffice-1.6.3
PKGREVISION=	6
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-1.6.3/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite

PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/
PATCHFILES=	koffice-xpdf-CVE-2007-3387.diff koffice-1.6.3-xpdf2-CVE-2007-4352-5392-5393.diff

CONFLICTS+=	koffice3-[0-9]*

# to unpack krita/plugins/convolutionfilters properly on NetBSD 1.6
## EXTRACT_USING=		gtar

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes

GCC_REQD+=		2.95.3

PTHREAD_OPTS+=		require

PYTHON_VERSIONS_ACCEPTED=	24 23 # needs shared library
CONFIGURE_ENV+=			PYTHONDIR=${LOCALBASE:Q}
CONFIGURE_ENV+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

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
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

.include "../../lang/python/pyversion.mk"
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/poppler-qt/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
