# $NetBSD: Makefile,v 1.9 2001/12/21 21:19:28 skrll Exp $

DISTNAME=	koffice-1.1.1
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1/src/

.include "../../x11/kde2/Makefile.kde2"

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite with text processor, spreadsheet, etc.

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

REPLACE_PERL=		kpresenter/kprconverter.pl

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic

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

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
