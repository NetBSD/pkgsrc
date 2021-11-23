all: cutoggvorbis cutoggvorbis.1

cutoggvorbis.1: cutoggvorbis.1.gz
	gunzip cutoggvorbis.1.gz

.c.o:
	$(CC) $(CFLAGS) -c $<

cutoggvorbis: main.o
	$(CC) $(LDFLAGS) main.o -lm -o cutoggvorbis
