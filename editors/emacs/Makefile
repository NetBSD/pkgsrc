# New ports collection makefile for:	GNU emacs
# Version required:	20.2
# Date created:		11 October 1997
# Whom:			hubertf
#
# $NetBSD: Makefile,v 1.4 1998/01/24 04:42:43 hubertf Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.2
WRKSRC=		${WRKDIR}/emacs-20.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	hubertf@netbsd.org

BUILD_DEPENDS=  ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd --with-pop --with-x --with-x-toolkit=lucid
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

post-install:
.for file in emacs-20.2 emacsclient etags ctags b2m
	strip ${PREFIX}/bin/${file}
.endfor
.if (${OPSYS} != "NetBSD")
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.endif
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
