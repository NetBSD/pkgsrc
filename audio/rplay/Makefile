# $NetBSD: Makefile,v 1.39 2003/06/02 01:21:33 jschauma Exp $
#

DISTNAME=	rplay-3.3.2
CATEGORIES=	audio
MASTER_SITES=	ftp://rplay.doit.org/pub/rplay/ \
		http://rplay.doit.org/dist/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://rplay.doit.org/
COMMENT=	Network audio player

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		RPLAY_TARGET=generic	# XXX generic, or oss, or sun?

INFO_FILES=	RPLAY.info RPTP.info librplay.info rplay.info
RCD_SCRIPTS=	rplayd

pre-configure:
	cd ${WRKSRC}/doc; for manpage in *.[0-9]; do			\
		${SED}	-e "s|/usr/local/etc|${PKG_SYSCONFDIR}|g"	\
			-e "s|/usr/local|${PREFIX}|g"			\
			$${manpage} > $${manpage}.pdone;		\
		${MV} -f $${manpage}.pdone $${manpage};			\
	done

.include "../../audio/gsm/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/rx/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
