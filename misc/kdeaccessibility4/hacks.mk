# $NetBSD: hacks.mk,v 1.1.1.1 2009/10/02 20:41:53 markd Exp $

post-patch:
	cp ${BUILDLINK_PREFIX.kdelibs}/include/kspeech.h ${WRKSRC}/kttsd/kttsd/kspeech.h
