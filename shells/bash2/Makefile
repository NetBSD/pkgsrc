# $NetBSD: Makefile,v 1.43 2003/02/14 18:59:19 wiz Exp $
#

DISTNAME=	bash-2.05b
PKGNAME=	bash-2.05.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

CONFLICTS=	static-bash-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT='${INSTALL_SCRIPT}'

PKG_SHELL=		${PREFIX}/bin/bash

.include "../../mk/bsd.prefs.mk"

.if defined(BASH_STATIC)
.  if !empty(BASH_STATIC:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-static-link
.  endif
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/bash.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bashbug.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
