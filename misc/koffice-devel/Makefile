# $NetBSD: Makefile,v 1.2 2003/12/03 10:25:15 kleink Exp $

DISTNAME=	koffice-1.2.94
#PKGREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/koffice-1.2.94/src/ \
		ftp://ftp.us.kde.org/pub/kde/unstable/koffice-1.2.94/src/ \
		ftp://ftp.de.kde.org/pub/kde/unstable/koffice-1.2.94/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite

CONFLICTS+=	koffice3-[0-9]*

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCC_REQD=		2.95.3

PTHREAD_OPTS+=		require

PYTHON_VERSIONS_ACCEPTED=	23 # needs shared library
CONFIGURE_ENV+=			PYTHONDIR="${LOCALBASE}"

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
.include "../../textproc/aspell/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/jasper/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
