# $NetBSD: Makefile,v 1.7 1998/04/15 10:38:20 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/29 09:20:00 obrien Exp
#

DISTNAME=	indent-1.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	kchowksey@hss.hns.com

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=	yes

MAN1=		indent.1

MAKEFILE=	makefile

# agc - force makeinfo to create a new info file with the Dir info.
pre-install:
	@rm -f indent.info

post-install:
	@strip ${PREFIX}/bin/indent
	@test -d ${PREFIX}/info || ${MKDIR} ${PREFIX}/info  \
		&& chmod a+rx ${PREFIX}/info
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  if [ -f /usr/share/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	  else \
	    ${TOUCH} ${PREFIX}/info/dir ; \
	  fi ; \
	fi
	@install-info ${PREFIX}/info/indent.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
