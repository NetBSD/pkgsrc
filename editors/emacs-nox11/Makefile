# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:53 wiz Exp $

DISTNAME=	emacs-21.4a
PKGNAME=	emacs-nox11-21.4a
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*
CONFLICTS+=	emacs-[0-9]*

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

PATCHDIR=	${.CURDIR}/../emacs/patches
FILESDIR=	${.CURDIR}/../emacs/files
DISTINFO_FILE=	${.CURDIR}/../emacs/distinfo

# needed for 21.4a, can probably go away on next update
WRKSRC=         ${WRKDIR}/emacs-21.4
PLIST_SUBST+=   EMACSVERSION=21.4

CONFIGURE_ARGS+=--without-x

INFO_FILES=	ada-mode autotype ccmode cl dired-x ebrowse ediff efaq emacs
INFO_FILES+=	emacs-mime eshell eudc forms gnus idlwave message mh-e pcl-cvs
INFO_FILES+=	reftex sc speedbar vip viper widget woman

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp
	${CP} ${FILESDIR}/amd64.h ${WRKSRC}/src/m

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
