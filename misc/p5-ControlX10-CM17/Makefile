# $NetBSD: Makefile,v 1.7 2004/04/27 02:24:09 snj Exp $

DISTNAME=	ControlX10-CM17-0.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cx7
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ControlX10/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/x10.d/index.html
COMMENT=	Perl5 module for controlling the X10 CM17A controller

DEPENDS+=	p5-Device-SerialPort>=0.07:../../comms/p5-Device-SerialPort

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ControlX10/CM17/.packlist

# We don't actually install the example perl script, but we patch it
# to be useful, just the same.
#
post-patch:
	cd ${WRKSRC}; for file in eg/eg_cm17.plx; do			\
		${SED}	-e "s|/usr/bin/perl|${PERL5}|g"			\
			-e "s|/dev/ttyS0|${DEFAULT_SERIAL_DEVICE}|g"	\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
