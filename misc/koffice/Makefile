# $NetBSD: Makefile,v 1.40 2004/04/26 02:06:23 snj Exp $

DISTNAME=	koffice-1.3
PKGREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.3/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.3/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite

CONFLICTS+=	koffice3-[0-9]*

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

GCC_REQD+=		2.95.3

PTHREAD_OPTS+=		require

PYTHON_VERSIONS_ACCEPTED=	23 23pth # needs shared library
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

post-install:
	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

.include "../../lang/python/pyversion.mk"
.include "../../converters/wv2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
