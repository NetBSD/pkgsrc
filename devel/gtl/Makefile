# $NetBSD: Makefile,v 1.26 2007/12/01 11:16:44 rillig Exp $

DISTNAME=		GTL-1.2.1
PKGNAME=		gtl-1.2.1
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.infosun.fmi.uni-passau.de/GTL/
COMMENT=		C++ graph data structure library based on the STL

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

# previous version of the same
CONFLICTS=		gtl0-[0-9]*

LICENSE=		no-commercial-use

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}

DOCDIR=		${PREFIX}/share/doc/GTL

INTERACTIVE_STAGE=	fetch

FETCH_MESSAGE= \
"With the release of version 1.0.0 the download policy of GTL has been" \
"changed. GTL can be downloaded free of charge for non-commercial use." \
"Please follow the steps below to get access to the download archive:" \
"" \
"Send an email to gtl-download@infosun.fmi.uni-passau.de containing the" \
"following information:" \
"- Your Name" \
"- Your Affiliation" \
"- And your email address. Please use your academic address, e.g. .edu," \
"  if you have. Otherwise your are classified as a \"commercial\" user." \
"As soon as possible you will receive an answer from the GTL Team" \
"containing the access code to the download page." \
"" \
"If you intend to use GTL commercially please send an email to" \
"brandenb@fmi.uni-passau.de."

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/icons
	cd ${WRKSRC}/doc; \
		${INSTALL_DATA} *.html style.css ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/*.jpeg ${DOCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/doc/userguide/GTL.ps ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
