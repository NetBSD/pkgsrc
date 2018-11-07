package histogram

import (
	"fmt"
	"io"
	"sort"
)

type Histogram struct {
	histo map[string]int
}

func New() *Histogram {
	return &Histogram{make(map[string]int)}
}

func (h *Histogram) Add(s string, n int) {
	h.histo[s] += n
}

func (h *Histogram) PrintStats(out io.Writer, caption string, limit int) {
	type row struct {
		s     string
		count int
	}

	entries := make([]row, len(h.histo))

	n := 0
	for s, count := range h.histo {
		entries[n] = row{s, count}
		n++
	}

	sort.SliceStable(entries, func(i, j int) bool {
		ei := entries[i]
		ej := entries[j]
		return ej.count < ei.count || (ei.count == ej.count && ei.s < ej.s)
	})

	for i, entry := range entries {
		if limit >= 0 && i >= limit {
			break
		}
		_, _ = fmt.Fprintf(out, "%s %6d %s\n", caption, entry.count, entry.s)
	}
}
