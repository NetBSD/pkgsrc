# $NetBSD: Makefile,v 1.20 2003/05/02 11:55:55 wiz Exp $

DISTNAME=	koffice-1.2.1
PKGREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.2.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.2.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.2.1/src/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.koffice.org/bugfixes/
PATCHFILES=	1.2.1_kword_crashes.diff
PATCH_DIST_ARGS?=	-d ${WRKSRC}/kword -p0

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite

CONFLICTS+=	koffice3-[0-9]*

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PTHREAD_OPTS+=		require
GCC_REQD=		2.95.3

REPLACE_PERL=		kpresenter/kprconverter.pl

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

post-install:
	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

.include "../../lang/gcc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
