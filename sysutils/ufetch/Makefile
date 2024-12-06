# $NetBSD: Makefile,v 1.9 2024/12/06 11:52:58 pin Exp $

DISTNAME=	ufetch-v0.4
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=jschx/}
GITLAB_PROJECT=	ufetch
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/jschx/ufetch/
COMMENT=	Tiny system info for Unix-like Operating Systems
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == Linux
FLAVOR=	${LOWER_OPSYS}
.elif ${OPSYS} == Darwin
FLAVOR=	macos
.else
BROKEN=	"Unsupported OS"
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ufetch-${FLAVOR}	\
		${DESTDIR}${PREFIX}/bin/ufetch
.if ${OPSYS} == "Linux"
.  for i in *bsd linux macos
	${RUN}${FIND} ${WRKSRC} -maxdepth 1 -type f	\
		-name ufetch-${i} -delete
.  endfor
.  for f in ufetch-*
	${INSTALL_SCRIPT} ${WRKSRC}/${f}		\
		${DESTDIR}${PREFIX}/bin
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
