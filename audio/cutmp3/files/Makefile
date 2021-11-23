all: cutmp3

.c.o:
	$(CC) $(CFLAGS) -c $<

cutmp3: main.o mpglib.o
	$(CC) $(LDFLAGS) main.o mpglib.o -lreadline -lcurses -lm -o cutmp3
