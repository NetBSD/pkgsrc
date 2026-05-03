# $NetBSD: Makefile,v 1.18 2026/05/03 06:21:25 vins Exp $

DISTNAME=	ksh93-1.0.10
PKGREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksh93/}
GITHUB_PROJECT=	ksh
GITHUB_TAG=	v${PKGVERSION_NOREV:S/beta/-beta/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.kornshell.com/
COMMENT=	Actively developed fork of AT&T KornShell 93u+
LICENSE=	epl-v1.0

CONFLICTS+=		ast-ksh-[0-9]* static-ast-ksh-[0-9]*

FORTIFY_SUPPORTED=	no
MKPIE_SUPPORTED=	no

CFLAGS.SunOS+=		-D__EXTENSIONS__

PKG_SYSCONFSUBDIR=	ksh93

FUNDIR=			${PREFIX}/libexec/ksh93
EGDIR=			${PREFIX}/share/examples/ksh93
CONF_FILES+=		${EGDIR}/kshrc ${PKG_SYSCONFDIR}/kshrc

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	src/cmd/ksh93/Mamfile src/cmd/ksh93/SHOPT.sh \
			src/cmd/ksh93/data/builtins.c src/cmd/ksh93/sh.1 \
			src/cmd/ksh93/data/msg.c src/cmd/ksh93/kshrc
SUBST_SED.conf+=	-e "s:/etc/ksh.kshrc:${PKG_SYSCONFDIR}/kshrc:g"
SUBST_SED.conf+=	-e "s:/etc/ksh_audit:${PKG_SYSCONFDIR}/ksh_audit:g"
SUBST_VARS.conf+=	FUNDIR
SUBST_MESSAGE.conf=	Setting configuration file path

MAKE_FLAGS+=		SHELL=${SH:Q} CC=${CC:Q}	\
			CCFLAGS=${CFLAGS:M*:Q}		\
			LDFLAGS=${LDFLAGS:M*:Q}

INSTALL_ENV+=		MANDIR=${PKGMANDIR}

PKG_SHELL=	bin/ksh93

post-extract:
	${RUN} cp ${FILESDIR}/kshrc ${WRKSRC}/src/cmd/ksh93

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} 		\
		${SH} ./bin/package make ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV}	\
		${SH} ./bin/package install ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV}		\
		${SH} ./bin/package test

.include "../../mk/bsd.pkg.mk"
