# $NetBSD: Makefile,v 1.2 2002/05/02 20:21:31 drochner Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=--with-x
CONFIGURE_ARGS+=--with-x-toolkit=athena

.include "../../graphics/xpm/buildlink.mk"
CONFIGURE_ARGS+=--with-xpm
.include "../../graphics/jpeg/buildlink.mk"
CONFIGURE_ARGS+=--with-jpeg
.include "../../graphics/tiff/buildlink.mk"
CONFIGURE_ARGS+=--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink.mk"
CONFIGURE_ARGS+=--with-gif
.include "../../graphics/png/buildlink.mk"
CONFIGURE_ARGS+=--with-png

INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff \
		    ccmode message widget reftex forms

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
