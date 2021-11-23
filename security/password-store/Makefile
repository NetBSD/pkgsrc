# $NetBSD: Makefile,v 1.14 2021/11/23 07:50:15 pho Exp $

DISTNAME=	password-store-1.7.3
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://git.zx2c4.com/password-store/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://www.passwordstore.org/
COMMENT=	Standard UNIX password manager
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	gmake pax bash:run

DEPENDS+=	base64>=1.5:../../converters/base64
DEPENDS+=	getopt>=1.1.6:../../misc/getopt
DEPENDS+=	gnupg2>=2.0.26:../../security/gnupg2
DEPENDS+=	tree>=1.7.0:../../sysutils/tree

EGDIR=			share/examples/password-store
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${EGDIR}/contrib
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

REPLACE_BASH+=	src/password-store.sh
REPLACE_BASH+=	tests/*.sh

SUBST_CLASSES+=		fixsh
SUBST_STAGE.fixsh=	pre-configure
SUBST_MESSAGE.fixsh=	Fixing shell script
SUBST_FILES.fixsh=	src/password-store.sh
SUBST_SED.fixsh+=	-e 's,GETOPT="getopt",GETOPT="${PREFIX}/bin/getopt",'
SUBST_SED.fixsh+=	-e "s,SHRED=\"shred -f -z\",SHRED=\"${RM} -f -P\","
SUBST_SED.fixsh+=	-e 's,BASE64="base64",BASE64="${PREFIX}/bin/base64",'

TEST_TARGET=		test

.include "options.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/password-store.sh	\
		${DESTDIR}${PREFIX}/bin/pass
	${INSTALL_SCRIPT} ${WRKSRC}/man/example-filter.sh	\
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/man/pass.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pass.1
	cd ${WRKSRC}/contrib &&						\
		${PAX} -wr * -s',.*\.orig$$,,' -s',.*\.gitignore$$,,'	\
			${DESTDIR}${PREFIX}/${EGDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/src/completion/pass.bash-completion \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/pass
	${INSTALL_DATA} ${WRKSRC}/src/completion/pass.fish-completion \
		${DESTDIR}${PREFIX}/share/fish/completions/pass.fish
	${INSTALL_DATA} ${WRKSRC}/src/completion/pass.zsh-completion \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_pass

.include "../../mk/bsd.pkg.mk"
