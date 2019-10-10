# $NetBSD: Makefile,v 1.12 2019/10/10 13:38:05 wiz Exp $

DISTNAME=	enigmail-2.1.2
PKGNAME=	thunderbird-${DISTNAME}
CATEGORIES=	mail security
MASTER_SITES=	http://www.enigmail.net/download/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.enigmail.net/
COMMENT=	GnuPG support for mail/thunderbird
LICENSE=	(mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1) AND mpl-2.0

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=68:../../mail/thunderbird

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

USE_TOOLS+=	gmake perl sed unzip zip

# It doesn't work -- noted also here:
# https://aur.archlinux.org/packages/th/thunderbird-enigmail/PKGBUILD
MAKE_JOBS_SAFE=	no

DEPENDS+=		gnupg2>=2.0.7:../../security/gnupg2
DEPENDS+=		pinentry-gtk2-[0-9]*:../../security/pinentry-gtk2

REPLACE_PERL+=	util/fixlang.pl
REPLACE_PERL+=	util/make-lang-xpi.pl

PYTHON_VERSIONS_ACCEPTED=	 27 # as of 2.1.2
REPLACE_PYTHON+=	util/checkFiles.py
REPLACE_PYTHON+=	util/run-tests.py

WRKSRC=		${WRKDIR}/enigmail
GNU_CONFIGURE=	yes

ENIGMAILXPI=	enigmail-${PKGVERSION_NOREV}.xpi
XPIFILE=	${WRKSRC}/build/${ENIGMAILXPI}

# Build instructions: https://www.enigmail.net/download/build_instructions.php
# Installation of extensions: http://kb.mozillazine.org/Installing_extensions
# Model installation: https://aur.archlinux.org/packages/th/thunderbird-enigmail/PKGBUILD
do-install:
	${RUN} EMID=`${SED} -n '/.*<em:id>\\(.*\\)<\\/em:id>.*/{s//\\1/p;q;}' \
		${WRKSRC}/package/install.rdf` && \
		${INSTALL_DATA_DIR} ${DESTDIR}${XPIDIR}/"$$EMID" && \
		unzip -d ${DESTDIR}${XPIDIR}/"$$EMID" \
		${XPIFILE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
