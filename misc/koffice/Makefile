# $NetBSD: Makefile,v 1.65 2005/10/02 12:35:37 seb Exp $

DISTNAME=	koffice-1.4.1
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.4.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.4.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.4.1/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite

CONFLICTS+=	koffice3-[0-9]*

# to unpack krita/plugins/convolutionfilters properly on NetBSD 1.6
EXTRACT_USING=		gtar

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes

GCC_REQD+=		2.95.3

PTHREAD_OPTS+=		require

PYTHON_VERSIONS_ACCEPTED=	24 23 # needs shared library
CONFIGURE_ENV+=			PYTHONDIR="${LOCALBASE}"
CONFIGURE_ENV+=			PYVERSSUFFIX="${PYVERSSUFFIX}"

REPLACE_PERL+=		lib/store/fix_storage.pl
REPLACE_PERL+=		admin/config.pl
REPLACE_PERL+=		admin/bcheck.pl
REPLACE_PERL+=		admin/conf.change.pl
REPLACE_PERL+=		admin/cvs-clean.pl
REPLACE_PERL+=		kword/templates/make_template.pl
REPLACE_PERL+=		tools/scripts/gdb_output_to_text.pl
REPLACE_PERL+=		tools/thesaurus/extract.pl
REPLACE_PERL+=		kpresenter/kprconverter.pl

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	krita/ui/widgets/kis_wdg_autogradient.ui \
			krita/ui/kis_previewwidgetbase.ui \
			krita/ui/wdgnewimage.ui \
			krita/ui/wdgcolorsettings.ui \
			krita/ui/wdglayerbox.ui \
			krita/plugins/screenshot/ksnapshotwidget.ui \
			krita/plugins/convolutionfilters/kis_custom_convolution_filter_configuration_base_widget.ui \
			krita/plugins/colorspaceconversion/wdgconvertcolorspace.ui \
			kpresenter/imageEffectBase.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "options.mk"

post-install:
	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

.include "../../lang/python/pyversion.mk"
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/wv2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
