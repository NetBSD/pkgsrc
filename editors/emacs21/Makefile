# $NetBSD: Makefile,v 1.3 2002/09/21 11:30:59 jlam Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-toolkit=athena

.include "../../graphics/xpm/buildlink2.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink2.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink2.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink2.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink2.mk"
CONFIGURE_ARGS+=	--with-png

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
