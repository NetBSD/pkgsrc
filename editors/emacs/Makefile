# New ports collection makefile for:	GNU emacs
# Version required:	20.2
# Date created:		11 October 1997
# Whom:			hubertf
#
# $Id: Makefile,v 1.2 1997/10/11 21:32:53 hubertf Exp $
#

DISTNAME=	emacs-20.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	hubertf@netbsd.org
OPSYS!= 	uname -s


WRKSRC=		${WRKDIR}/emacs-20.2
BUILD_DEPENDS=  ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS=	${MACHINE_ARCH}--netbsd --with-pop --with-x --with-x-toolkit=lucid
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
