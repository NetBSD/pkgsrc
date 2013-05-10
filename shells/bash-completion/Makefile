# $NetBSD: Makefile,v 1.7 2013/05/10 12:01:50 imil Exp $
#
# Note to packagers:
# packages installing additional completion files should drop
# them into ${DESTDIR}${PREFIX}/share/bash-completion.d
# with the name of the package as file name.

DISTNAME=	bash-completion-2.1
CATEGORIES=	shells
MASTER_SITES=	http://bash-completion.alioth.debian.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bash-completion.alioth.debian.org/
COMMENT=	Programmable completion specifications for bash
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gmake

USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,/etc/bash_completion.d,${PREFIX}/share/bash-completion.d,g"
SUBST_SED.path+=	-e "s,/etc/bash_completion,${PREFIX}/share/bash-completion/bash_completion,g"
SUBST_STAGE.path=	pre-build
SUBST_FILES.path+=	README
SUBST_MESSAGE.path=	Fixing path to completion files.

#do-build:

#do-install:
#	${INSTALL_DATA} ${WRKSRC}/README \
#		${DESTDIR}${PREFIX}/share/doc/bash-completion
#	${INSTALL_DATA} ${WRKSRC}/bash_completion \
#		${DESTDIR}${PREFIX}/share/bash-completion
#	${INSTALL_DATA} ${WRKSRC}/bash_completion.sh \
#		${DESTDIR}${PREFIX}/share/bash-completion
#	${INSTALL_DATA} ${WRKSRC}/contrib/* \
#	    ${DESTDIR}${PREFIX}/share/bash-completion.d

.include "../../mk/bsd.pkg.mk"
