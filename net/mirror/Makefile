# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:29 frueauf Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.8
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	packages@netbsd.org

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirrormaster.1

post-configure:
	cd ${WRKSRC} ; ${SED} \
		s:/usr/local:${PREFIX}: <mirror.pl >mirror.pl.BAK ; \
		${MV} mirror.pl.BAK mirror.pl
	cd ${WRKSRC} ; for i in do_unlinks mirror mirror.pl mm \
		pkgs_to_mmin ; do \
		${SED} s:/usr/bin/perl:${PREFIX}/bin/perl: <$$i >$$i.BAK ; \
		${MV} $$i.BAK $$i ; done

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include "../../mk/bsd.pkg.mk"
