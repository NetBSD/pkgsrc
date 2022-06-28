# $NetBSD: Makefile,v 1.44 2022/06/28 11:35:52 wiz Exp $

DISTNAME=		mksh-R59b
PKGNAME=		${DISTNAME:S/-R/-/}
PKGREVISION=		2
CATEGORIES=		shells
MASTER_SITES=		# maintained locally
DISTFILES=		# empty

MAINTAINER=		jperkin@pkgsrc.org
HOMEPAGE=		http://mirbsd.de/mksh
COMMENT=		MirBSD Korn Shell
LICENSE=		miros

BOOTSTRAP_PKG=		yes
NO_CHECKSUM=		yes

WRKSRC=			${WRKDIR}/mksh

LIBS.Interix+=		-lcrypt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/mksh

.include "../../mk/bsd.prefs.mk"

#
# If mksh is currently in use as the bootstrap shell then do not enable
# PKG_SHELL as it can cause circular problems (its +INSTALL script will
# require the shell itself).  This match is deliberate to catch both of
# the prefixes used during bootstrap, we can't simply use LOCALBASE.
#
.if ${TOOLS_PLATFORM.sh:N?*/bin/mksh}
PKG_SHELL=		bin/mksh
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LIBS=${LIBS:Q} \
	    ${TOOLS_SHELL} ${WRKSRC}/Build.sh -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${DESTDIR}${PREFIX}/bin/mksh
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${DESTDIR}${PREFIX}/share/examples/mksh/

# For check-portability's double brackets check.
# This should be patched instead.
CHECK_PORTABILITY_SKIP+=	Build.sh

# Uncomment this if you want to run the regression tests
#USE_TOOLS+=			perl
#do-test:
#	${WRKSRC}/test.sh -v

.include "../../mk/bsd.pkg.mk"
