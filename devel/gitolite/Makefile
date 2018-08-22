# $NetBSD: Makefile,v 1.26 2018/08/22 09:43:30 wiz Exp $

GLVER=		3.6.6
DISTNAME=	gitolite-${GLVER}
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sitaramc/}
GITHUB_PROJECT=	gitolite
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sitaramc/gitolite/wiki
COMMENT=	Gitolite allows you to host Git repositories easily and securely
LICENSE=	gnu-gpl-v2

DEPENDS+=	git-base>=1.6.6:../../devel/git-base

USE_LANGUAGES=	# none
USE_TOOLS+=	pax perl:run

NO_BUILD=	yes

REPLACE_PERL=	src/lib/* src/VREF/* src/triggers/* src/triggers/*/* \
		src/commands/* src/gitolite* src/lib/Gitolite/*/*
REPLACE_SH=	src/VREF/* src/triggers/* src/triggers/post-compile/* \
		src/commands/*

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_MESSAGE.perl=	Set PERL5
SUBST_FILES.perl=	src/gitolite
SUBST_FILES.perl+=	src/lib/Gitolite/Hooks/*
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},g'

INSTALLATION_DIRS+=	bin lib \
			share/doc/gitolite \
			libexec/gitolite \
			${PERL5_INSTALLVENDORARCH}

pre-install:
	${FIND} ${WRKSRC} -type f \
		-name "*.orig" -exec ${RM} -f {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gitolite ${DESTDIR}${PREFIX}/libexec/gitolite
	${INSTALL_SCRIPT} ${WRKSRC}/src/gitolite-shell ${DESTDIR}${PREFIX}/libexec/gitolite

	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../libexec/gitolite/gitolite gitolite

	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/share/gitolite
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/gitolite
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DESTDIR}${PREFIX}/share/gitolite

	cd ${WRKSRC}/src/lib && pax -rw -pmp Gitolite \
		${DESTDIR}${PERL5_INSTALLVENDORARCH}

	cd ${WRKSRC}/src && pax -rw -pmp triggers \
		${DESTDIR}${PREFIX}/libexec/gitolite
	cd ${WRKSRC}/src && pax -rw -pmp syntactic-sugar \
		${DESTDIR}${PREFIX}/libexec/gitolite
	cd ${WRKSRC}/src && pax -rw -pmp VREF \
		${DESTDIR}${PREFIX}/libexec/gitolite
	cd ${WRKSRC}/src && pax -rw -pmp commands \
		${DESTDIR}${PREFIX}/libexec/gitolite

.include "../../lang/perl5/dirs.mk"
.include "../../mk/bsd.pkg.mk"
