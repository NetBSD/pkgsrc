# $NetBSD: Makefile,v 1.2 1997/10/06 14:30:58 agc Exp $
# New ports collection makefile for:   indent
# Version required:    1.9.1
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/29 09:20:00 obrien Exp
#
        
DISTNAME=      indent-1.9.1
CATEGORIES=    devel
MASTER_SITES=  ${MASTER_SITE_GNU}

GNU_CONFIGURE=	yes

MAINTAINER=    kchowksey@hss.hns.com
        
MAN1=          indent.1

OPSYS!= uname -s

post-install:
	@strip ${PREFIX}/bin/indent
.if (${OPSYS} != "NetBSD")
# agc - this assumes /usr/share/info/dir and install-info
	@test -d ${PREFIX}/info || ${MKDIR} ${PREFIX}/info  \
		&& chmod a+rx ${PREFIX}/info
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  if [ -f /usr/share/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	  else \
	    touch ${PREFIX}/info/dir ; \
	  fi ; \
	fi
	@install-info ${PREFIX}/info/indent.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
