# $NetBSD: Makefile,v 1.7 1998/05/13 14:04:58 frueauf Exp $
#

DISTNAME=	pilot-link.0.8.11
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	sommerfeld@alum.mit.edu

STRIPFLAG=
GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 install-memo.1 \
		install-user.1 pilot-xfer.1 read-ical.1

# use "default" configure because overriding INSTALL_PROGRAM does the
# wrong thing for libtool-based packages like pilot-link...

do-configure:
	@(cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
