PROG=m
SRCS=libmerkle.c main.c
WARNS=6
MKMAN=no
CPPFLAGS+=-g -O0
LDFLAGS+=-g -O0

LDADD+=	-lmultigest

.include <bsd.prog.mk>

t: ${PROG}
	@echo "1. basic test"
	./${PROG} 1.in > 1.out
	diff 1.expected 1.out
	rm -f 1.out
	@echo "2. blocksize"
	./${PROG} -b 1024 1.in > 2.out
	diff 2.expected 2.out
	rm -f 2.out
	@echo "3. algorithm"
	./${PROG} -a md5 1.in > 3.out
	diff 3.expected 3.out
	rm -f 3.out
	@echo "4. verify digests"
	./${PROG} -b 2048 1.in > 4.out
	diff 4.expected 4.out
	rm -f 4.out
	@echo "5. stdin"
	./${PROG} < 1.in > 5.out
	diff 5.expected 5.out
	rm -f 5.out
	@echo "6. concatenated digests"
	./${PROG} -a rmd160,sha1 1.in > 6.out
	diff 6.expected 6.out
	rm -f 6.out
	@echo "7. concatenated digests"
	./${PROG} -a md5,sha256 1.in > 7.out
	diff 7.expected 7.out
	rm -f 7.out
	@echo "8. concatenated digests"
	./${PROG} -a sha512,sha256 1.in > 8.out
	diff 8.expected 8.out
	rm -f 8.out
	@echo "9. verify"
	-./${PROG} -V 1.sum 2.in > 9.out
	diff 9.expected 9.out
	rm -f 9.out
	@echo "10. verify again"
	./${PROG} -a sha512,sha256 1.in > 2.sum
	-./${PROG} -V 2.sum 2.in > 10.out
	diff 10.expected 10.out
	rm -f 2.sum 10.out
	@echo "11. verify again again"
	./${PROG} -b 128 -a sha512,sha256 1.in > 2.sum
	-./${PROG} -V 2.sum 2.in > 11.out
	diff 11.expected 11.out
	rm -f 2.sum 11.out
	@echo "12. crc32c algorithm"
	./${PROG} -a crc32c 1.in > 12.out
	diff 12.expected 12.out
	rm -f 12.out
	@echo "13. crc32c algorithm verify"
	./${PROG} -b 32 -a crc32c 1.in > 13.sum
	-./${PROG} -V 13.sum 2.in > 13.out
	diff 13.expected 13.out
	rm -f 13.sum 13.out
