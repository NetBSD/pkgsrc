# $NetBSD: Makefile,v 1.55 2003/04/14 07:38:42 uebayasi Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.3
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && \
    (empty(OS_VERSION:M[0-1].[0-5]*) && empty(OS_VERSION:M1.6[A-P]*))
# If using GNU ld 2.13.2.1 or later, avoid creating combined reloc
# sections and .data reloc sections, both of which Emacs can't handle
# properly.  Analyzed by Stephen Ma.
LDFLAGS+=	-Wl,-z,nocombreloc
.endif

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
