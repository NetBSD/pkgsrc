# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:00 tv Exp $

DISTNAME=	koffice-1.1.1
PKGREVISION=	7
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1/src/

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

CONFLICTS=	koffice3-[0-9]*

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite with text processor, spreadsheet, etc.

.include "../../mk/bsd.prefs.mk"
.include "../../x11/kde2/Makefile.kde2"

USE_BUILDLINK3=		yes
REPLACE_PERL=		kpresenter/kprconverter.pl

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.if ${OPSYS} == "NetBSD"
#
# On egcs-1.1.2, the C++ compiler system isn't quite ISO-compliant.  It lacks
# a std::auto_ptr implementation in <memory>, doesn't handle static inline
# functions in headers properly (although that concept, in itself, is quite
# flawed), and just plain has bugs when compiling large functions with
# optimization.  For certains parts of KOffice, we pass in
# ${OPTIMIZATION_BUG_CXXFLAGS}, which is meant to be appended to
# ${KDE_CXXFLAGS} so that it can turn off all code optimization by the
# compiler.
#
MAKE_ENV+=		OPTIMIZATION_BUG_CXXFLAGS="-O0"
.endif

post-install:
	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
