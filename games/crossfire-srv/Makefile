# $NetBSD: Makefile,v 1.17 2005/05/16 01:15:31 jlam Exp $
#

DISTNAME=	crossfire-1.0.0
PKGNAME=	crossfire-server-1.0.0
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.scruz.net/users/mwedel/public/
DISTFILES=	${CF_SRC} ${CF_MAPS}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-1.0.0.tar.bz2
CF_MAPS=	crossfire-1.0.0-maps.tar.bz2

USE_X11=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-includes=-I${LOCALBASE}/include
PKGSRC_USE_TOOLS+=	gtar

MAKE_ENV+=	EXTRA_INCLUDES=-I${LOCALBASE}/include

REPLACE_PERL=	lib/xpmtopix.pl lib/adm/check-xpm.pl lib/adm/make_xpm_file.pl
REPLACE_PERL+=	lib/adm/map_expand.pl lib/adm/mapslitter.pl
REPLACE_PERL+=	lib/adm/archsearch.pl lib/adm/collect_images.pl
REPLACE_PERL+=	lib/collect.pl lib/util.pl lib/checkarch.pl
REPLACE_PERL+=	utils/crossloop.pl utils/metaserver.pl
REPLACE_PERL+=	doc/include_html.pl doc/playbook/make_index.pl
REPLACE_PERL+=	doc/spoiler-html/makeps.pl

post-install:
	cd ${LOCALBASE}/share/crossfire && \
	    ${GZCAT} ${DISTDIR}/${CF_MAPS} | ${GTAR} xmf -
	@${CHOWN} ${ROOT_USER}:games ${LOCALBASE}/bin/crossfire
	@${CHMOD} 2755 ${LOCALBASE}/bin/crossfire
	@${CHOWN} -R ${ROOT_USER}:games ${LOCALBASE}/share/crossfire
	@${CHOWN} -R ${ROOT_USER}:games ${LOCALBASE}/var/crossfire
	@${CHMOD} -R g+w ${LOCALBASE}/var/crossfire

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../devel/dmalloc/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
