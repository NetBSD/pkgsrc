# $NetBSD: Makefile,v 1.12 2015/01/02 22:34:02 wiz Exp $

DISTNAME=	idutils-4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=idutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code
LICENSE=	gnu-gpl-v3

CONFLICTS=	sh-utils>=2.0nb2 coreutils-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_prog_EMACS=no
INFO_FILES=		YES
MAKE_ENV+=		BSD_SETENV=${SETENV:Q}

# Don't byte-compile the .el file.
MAKE_FLAGS+=		elc_SCRIPTS=

LISPDIR=		${PREFIX}/share/emacs/site-lisp
INSTALLATION_DIRS=	${LISPDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/idutils.el ${DESTDIR}${LISPDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
