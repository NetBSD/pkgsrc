# $NetBSD: Makefile,v 1.69.2.1 2006/01/08 04:23:08 salo Exp $

DISTNAME=	koffice-1.4.2
PKGREVISION=	4
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.4.2/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.4.2/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.4.2/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
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
CONFIGURE_ENV+=			PYTHONDIR=${LOCALBASE:Q}
CONFIGURE_ENV+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

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
