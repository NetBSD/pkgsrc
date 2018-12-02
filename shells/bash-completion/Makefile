# $NetBSD: Makefile,v 1.11 2018/12/02 07:06:20 wiz Exp $
#
# Note to packagers:
# packages installing additional completion files should drop
# them into ${DESTDIR}${PREFIX}/share/bash-completion.d
# with the name of the package as file name.

DISTNAME=	bash-completion-2.8
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=scop/}
GITHUB_RELEASE= ${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bash-completion.alioth.debian.org/
COMMENT=	Programmable completion specifications for bash
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gmake

OWN_DIRS+=	share/bash-completion.d

USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,/etc/bash_completion.d,${PREFIX}/share/bash-completion.d,g"
SUBST_SED.path+=	-e "s,/etc/bash_completion,${PREFIX}/share/bash-completion/bash_completion,g"
SUBST_STAGE.path=	pre-build
SUBST_FILES.path+=	README
SUBST_MESSAGE.path=	Fixing path to completion files.

INSTALLATION_DIRS=	lib/pkgconfig

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/pkgconfig/bash-completion.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/bash-completion.pc

.include "../../mk/bsd.pkg.mk"
