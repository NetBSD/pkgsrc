# New ports collection makefile for:	zsh
# Version required:     	3.0.5
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $NetBSD: Makefile,v 1.5 1998/04/14 18:35:59 tron Exp $
# FreeBSD Id: Makefile,v 1.26 1997/09/26 08:23:14 torstenb Exp
#

DISTNAME=       zsh-3.0.5
PKGNAME=	zsh-3.0.5
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/zsh/ \
		ftp://ftp.sterling.com/zsh/ \
		ftp://ftp.rge.com/pub/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/pub/shells/zsh/ \
		ftp://mrrl.lut.ac.uk/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		ftp://ftp.ips.oz.au/pub/packages/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/

MAINTAINER=	torstenb@FreeBSD.ORG

OPSYS!=		uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=  ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=	yes
MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshexpn.1 zshmisc.1 \
		zshoptions.1 zshall.1 zshparam.1 zshzle.1

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${PREFIX}/bin/install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir

.include <bsd.port.mk>
