# $NetBSD: Makefile,v 1.1.1.1 2002/05/07 14:55:29 drochner Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.2
PKGNAME=	emacs-nox11-21.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*
CONFLICTS+=	emacs-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=--without-x

INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff \
		    ccmode message widget reftex forms

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
